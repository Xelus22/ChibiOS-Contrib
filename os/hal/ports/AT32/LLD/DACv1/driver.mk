ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB +=  $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/DACv1/hal_dac_lld.c
endif
else
PLATFORMSRC_CONTRIB += $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/DACv1/hal_dac_lld.c
endif

PLATFORMINC_CONTRIB += $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/DACv1