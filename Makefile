SUBDIRS=intro comparch ostruct pm thread schedule ps deadlock mm vm fs

all: slide handout release

slide:
ifeq ($(OS), Windows_NT)
	for %%x in ( $(SUBDIRS) ) do $(MAKE) -C %%x slide
else
	for subdir in $(SUBDIRS); do         \
		$(MAKE) -C $${subdir} all;       \
	done
endif

handout:
ifeq ($(OS), Windows_NT)
	for %%x in ( $(SUBDIRS) ) do $(MAKE) -C %%x handout
else
	for subdir in $(SUBDIRS); do         \
		$(MAKE) -C $${subdir} handout;       \
	done
endif

release:
ifeq ($(OS), Windows_NT)
	for %%x in ( $(SUBDIRS) ) do $(MAKE) -C %%x release
else
	for subdir in $(SUBDIRS); do         \
		$(MAKE) -C $${subdir} release;   \
	done
endif

clean:
ifeq ($(OS), Windows_NT)
	for %%x in ( $(SUBDIRS) ) do $(MAKE) -C %%x clean
else
	for subdir in $(SUBDIRS); do         \
		$(MAKE) -C $${subdir} clean;     \
	done
endif
