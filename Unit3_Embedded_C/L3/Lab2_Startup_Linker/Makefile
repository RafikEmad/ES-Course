CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=learn-in-depth_cortex-m3

all: $(Project_name).hex
	
startup.o: startup.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).hex: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin *.hex

clean:
	rm *.elf *.bin	*.hex	