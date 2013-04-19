CellProfiler Pipeline: http://www.cellprofiler.org
Version:2
DateRevision:20130401200712

LoadImages:[module_num:1|svn_version:\'Unknown\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Default Input Folder\x7CNone
    Check image sets for unmatched or duplicate files?:Yes
    Group images by metadata?:Yes
    Exclude certain files?:No
    Specify metadata fields to group by:site
    Select subfolders to analyze:
    Image count:2
    Text that these images have in common (case-sensitive):c1
    Position of this image in each group:1
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:20130405 a20_22 sirna dcf tnf001xy(?P<site>\x5B0-9\x5D\x5B0-9\x5D\x5B0-9\x5D)c1t(?P<tp>\x5B0-9\x5D\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\\\\\/\x5D(?P<well>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:img_nc
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):c2
    Position of this image in each group:2
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:20130405 a20_22 sirna dcf tnf001xy(?P<site>\x5B0-9\x5D\x5B0-9\x5D\x5B0-9\x5D)c2t(?P<tp>\x5B0-9\x5D\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\\\\\/\x5D(?P<well>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:img_er
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

WMC_Segment:[module_num:2|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Input image name\x3A:img_nc
    Output image name\x3A:img_nc_mask
    Gaussian Filter Size:2
    Rolling Ball Size:12
    Parabolic Kernel:No
    Noise:10
    Low Seed:10
    High Seed:50
    Low Bound:0.5
    High Bound:0.6
    Intensity Equalize:No

Binary_Watershed:[module_num:3|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Input image name\x3A:img_nc_mask
    Output image name\x3A:img_nc_mask_cut

IdentifyPrimaryObjects:[module_num:4|svn_version:\'Unknown\'|variable_revision_number:9|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the input image:img_nc_mask_cut
    Name the primary objects to be identified:obj_nc
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.1
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10

TrackObjects:[module_num:5|svn_version:\'Unknown\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Choose a tracking method:Distance
    Select the objects to track:obj_nc
    Select object measurement to use for tracking:None
    Maximum pixel distance to consider matches:50
    Select display option:Color and Number
    Save color-coded image?:No
    Name the output image:TrackedCells
    Select the motion model:Both
    Number of standard deviations for search radius:3
    Search radius limit, in pixel units (Min,Max):2.000000,10.000000
    Run the second phase of the LAP algorithm?:Yes
    Gap cost:40
    Split alternative cost:40
    Merge alternative cost:40
    Maximum gap displacement:50
    Maximum split score:50
    Maximum merge score:50
    Maximum gap:5
    Do you want to filter objects by lifetime?:No
    Filter using a minimum lifetime?:Yes
    Minimum lifetime:1
    Filter using a maximum lifetime?:No
    Maximum lifetime:100

SaveImages:[module_num:6|svn_version:\'Unknown\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the type of image to save:Image
    Select the image to save:img_nc_mask_cut
    Select the objects to save:obj_nc
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:img_nc
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_nc_mask
    Select file format to use:tif
    Output file location:Default Output Folder sub-folder\x7Cobj_nc
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

Cyto_NC_Segment:[module_num:7|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    NC_mask image name\x3A:img_nc_mask_cut
    NC_gray image name\x3A:img_nc
    Cyto_gray image name\x3A:img_er
    Output image name\x3A:cyto_mask
    Gaussian Filter Size:2
    Rolling Ball Size:16
    Noise:5
    Low Seed:10
    High Seed:50
    Dilate Distance:0

IdentifyPrimaryObjects:[module_num:8|svn_version:\'Unknown\'|variable_revision_number:9|show_window:False|notes:\x5B\'get cyto object\'\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the input image:cyto_mask
    Name the primary objects to be identified:obj_cyto
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.1
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10

SaveImages:[module_num:9|svn_version:\'Unknown\'|variable_revision_number:7|show_window:False|notes:\x5B\'save cyto objects\'\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the type of image to save:Image
    Select the image to save:cyto_mask
    Select the objects to save:obj_cyto
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:img_er
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:_cyto_mask
    Select file format to use:tif
    Output file location:Default Output Folder sub-folder\x7Cobj_cyto
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Color
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:Yes

IdentifyTertiaryObjects:[module_num:10|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the larger identified objects:obj_cyto
    Select the smaller identified objects:obj_nc
    Name the tertiary objects to be identified:obj_cyto_only
    Name the outline image:CytoplasmOutlines
    Retain outlines of the tertiary objects?:No

MeasureObjectSizeShape:[module_num:11|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select objects to measure:obj_cyto
    Select objects to measure:obj_nc
    Calculate the Zernike features?:Yes

MeasureObjectIntensity:[module_num:12|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Hidden:1
    Select an image to measure:img_er
    Select objects to measure:obj_cyto_only

MeasureObjectIntensity:[module_num:13|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Hidden:1
    Select an image to measure:img_nc
    Select objects to measure:obj_nc

RelateObjects:[module_num:14|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the input child objects:obj_nc
    Select the input parent objects:obj_cyto
    Calculate distances?:Centroid
    Calculate per-parent means for all child measurements?:No
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:15|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)]
    Select the input child objects:obj_nc
    Select the input parent objects:obj_cyto_only
    Calculate distances?:Centroid
    Calculate per-parent means for all child measurements?:No
    Calculate distances to other parents?:No
    Parent name:None
