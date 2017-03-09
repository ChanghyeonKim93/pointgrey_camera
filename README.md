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

6. 
