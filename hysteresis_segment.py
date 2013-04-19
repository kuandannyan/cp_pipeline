'''<b>Hysteresis_Segment</b> - perform WMC segmentation, just better GUI and integration
'''

import os
import sys

import cellprofiler.settings as cps
import cellprofiler.cpimage as cpi
import cellprofiler.cpmodule as cpm
import cellprofiler.utilities.jutil as jb
import imagej.imageprocessor as ijiproc


class Hysteresis_Segment(cpm.CPModule):
    module_name = "Hysteresis_Segment"
    category = "DImage"
    variable_revision_number = 1
        
    def create_settings(self):
        self.input_image_name = cps.ImageNameSubscriber("Input image name:",doc = "Gray-value image only, no color image")
        self.output_image_name = cps.ImageNameProvider("Output image name:","OutputImage", doc = "binary mask output")
        self.input_gaussian_filter = cps.Float("Gaussian Filter Size",value=2,doc="Gaussian filter size, recommended around 1~4")
        self.input_rolling_ball = cps.Float("Rolling Ball Size",value=256,doc="rolling ball kernel size, recommended around 1/4 of image dimensionality")
        self.input_low_seed = cps.Float("Low Seed",value=10,doc="initial value for foreground")
        self.input_high_seed = cps.Float("High Seed",value=50,doc="initial value for background")
        
    def settings(self):
        return [self.input_image_name, 
                self.output_image_name, 
                self.input_gaussian_filter,
                self.input_rolling_ball,
                self.input_low_seed,
                self.input_high_seed]
    

    def visible_settings(self):
        result = [self.input_image_name,
                  self.output_image_name,
                  self.input_gaussian_filter,
                  self.input_rolling_ball,
                  self.input_low_seed,
                  self.input_high_seed]
        return result

    def run(self, workspace):
        jb.attach()#initialize JVM
        
        input_image_name = self.input_image_name.value
        output_image_name = self.output_image_name.value
        self.gsize = self.input_gaussian_filter.value
        self.rsize = self.input_rolling_ball.value
        self.lowseed = self.input_low_seed.value
        self.highseed = self.input_high_seed.value
        
        image_set = workspace.image_set
        assert isinstance(image_set, cpi.ImageSet)
        
        #prepare input image        
        input_image = image_set.get_image(input_image_name, must_be_grayscale = True)        
        input_pixels = input_image.pixel_data
        ij_processor = ijiproc.make_image_processor((input_pixels*255.0).astype('float32'))
        #JavaScript API
        script = """       
        var img=Packages.ij.ImagePlus(name,ij_processor);
        Packages.ij.IJ.run(img, "8-bit", "");     
	var macro="g_size="+gsize+" r_size="+rsize+" low_edge="+lowseed+" high_edge="+highseed+" noise=-1";
        java.lang.System.out.println(macro);        
        Packages.ij.IJ.run(img, "Hysteresis Segment", macro);
        var output_proc=img.getProcessor();
        """
        #img.show();
        #Packages.ij.WindowManager.setCurrentWindow(img.getWindow());
        #"""
        in_params={
                   "name":output_image_name,
                   "ij_processor": ij_processor,
                   "gsize":self.gsize,
                   "rsize":self.rsize,
                   "lowseed":self.lowseed,
                   "highseed":self.highseed}
        out_params={"output_proc":None}
        r = jb.run_script(script, bindings_in = in_params,bindings_out = out_params)
        
        #prepare output image
        output_pixels = ijiproc.get_image(out_params["output_proc"], False)
        output_image = cpi.Image(output_pixels, parent_image = input_image)
        
        #write output
        image_set.add(output_image_name, output_image)
        
        if workspace.frame is not None:
            workspace.display_data.input_pixels = input_pixels
            workspace.display_data.output_pixels = output_pixels
        jb.detach()#close JVM

    def is_interactive(self):
        return False
    
    def display(self, workspace):
        #prepare plot area
        figure = workspace.create_or_find_figure(subplots=(2,1))
        lead_subplot = figure.subplot(0,0)
        
        #display original image
        figure.subplot_imshow_grayscale(
            0, 0,
            workspace.display_data.input_pixels,
            title = self.input_image_name.value)
        
        #display binary mask
        figure.subplot_imshow_grayscale(
            1, 0,
            workspace.display_data.output_pixels,
            title = self.output_image_name.value)
