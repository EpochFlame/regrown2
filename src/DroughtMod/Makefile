DROUGHT_FILES:=\
	$(BUILD_DIR)/src/DroughtMod/caveHole.o\
	$(BUILD_DIR)/src/DroughtMod/HallowMushi.o\
	$(BUILD_DIR)/src/DroughtMod/HallowMushiMgr.o\
	$(BUILD_DIR)/src/DroughtMod/efxDrought.o\
	$(BUILD_DIR)/src/DroughtMod/WraithYouIdiot.o\
	$(BUILD_DIR)/src/DroughtMod/PTankEffect.o\


DEPENDS += $(DROUGHT_FILES:.o=.d)

$(BUILD_DIR)/src/DroughtMod/DroughtMod.a: $(DROUGHT_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(DROUGHT_FILES) > build/DROUGHT_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/DROUGHT_ofiles
