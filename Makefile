# executable files for this directory
OBJECTS = avg_price.exe Sales_data.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include GNU_makefile_template

avg_price.exe: Sales_item.h
