#text2tif

text2tif is a fork of [Tesseract](https://github.com/tesseract-ocr/tesseract)'s [text2image](https://github.com/tesseract-ocr/tesseract/blob/b1c138284/training/text2image.cpp) program.

text2tif takes a text file as an input and generates a TIFF image and a *.box  file which contains bounding box coordinates for each glyph in the image.


##Compilng

```
g++ -o text2tif \
-std=c++11 \
-g -Wall -Wno-uninitialized -O0 -DDEBUG \
-DUSE_STD_NAMESPACE \
-DPANGO_ENABLE_ENGINE \
./training/boxchar.cpp \
./training/commandlineflags.cpp \
./training/degradeimage.cpp \
./training/fileio.cpp \
./training/ligature_table.cpp \
./training/normstrngs.cpp \
./training/pango_font_info.cpp \
./training/stringrenderer.cpp \
./training/tessopt.cpp \
./training/text2image.cpp \
./training/tlog.cpp \
./ccutil/ccutil.cpp \
./ccutil/errcode.cpp \
./ccutil/memry.cpp \
./ccutil/params.cpp \
./ccutil/scanutils.cpp \
./ccutil/serialis.cpp \
./ccutil/strngs.cpp \
./ccutil/tprintf.cpp \
./ccutil/unichar.cpp \
./ccutil/unicharmap.cpp \
./ccutil/unicharset.cpp \
-lm -pthread -llept -licui18n -licuuc \
-I/usr/local/include/leptonica \
-I./training -I./ccutil \
`pkg-config --cflags --libs pango` \
`pkg-config --cflags --libs cairo` \
`pkg-config --cflags --libs pangocairo` \
`pkg-config --cflags --libs fontconfig` \
`pkg-config --cflags --libs freetype2` \
`pkg-config --cflags --libs pangoft2`
```
