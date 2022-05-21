# executable files for this directory
OBJECTS = avg_price.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include GNU_makefile_template

avg_price.exe: avg_price.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o avg_price.exe \
		avg_price.o Sales_data.o

avg_price.o: Sales_data.h
Sales_data.o: Sales_data.h
