# pointgrey_camera
pointgrey flycapture2

1. download 'flycapture2-2.9.3.43-amd64' from the pointgrey website
2. extract the 'flycapture2-2.9.3.43-amd64'
3. at flycapture2-2.9.3.43-amd64, run sudo ./install_flycapture.sh
4. find the file , 'libflycapture.so', at '/usr/lib/~'
5. Write below at CMakeLists.txt for your c++ project.

set(PGRFLYCAP_LIB_DIR "/usr/lib" CACHE PATH " ") # pointgrey location
LIST(APPEND LINK_LIBS
${PGRFLYCAP_LIB_DIR}/libflycapture.so
}


// setting the camera properties 
#Setting Brightness Using the FlyCapture API


//Declare a Property struct.
Property prop;
//Define the property to adjust.
prop.type = BRIGHTNESS;
//Ensure the property is set up to use absolute value control.
prop.absControl = true;
//Set the absolute value of brightness to 0.5%.
prop.absValue = 0.5;
//Set the property.
error = cam.SetProperty( &prop );

#Setting Shutter Using the FlyCapture API
//Declare a Property struct.
Property prop;
//Define the property to adjust.
prop.type = SHUTTER;
//Ensure the property is on.
prop.onOff = true;
//Ensure auto-adjust mode is off.
prop.autoManualMode = false;
//Ensure the property is set up to use absolute value control.
prop.absControl = true;
//Set the absolute value of shutter to 20 ms.
prop.absValue = 20;
//Set the property.
error = cam.SetProperty( &prop );

#Setting Gain Using the FlyCapture API
//Declare a Property struct.
Property prop;
//Define the property to adjust.
prop.type = GAIN;
//Ensure auto-adjust mode is off.
prop.autoManualMode = false;
//Ensure the property is set up to use absolute value control.
prop.absControl = true;
//Set the absolute value of gain to 10.5 dB.
prop.absValue = 10.5;
//Set the property.

