# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  jlox_cpp_config = debug

else ifeq ($(config),release)
  jlox_cpp_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := jlox-cpp

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

jlox-cpp:
ifneq (,$(jlox_cpp_config))
	@echo "==== Building jlox-cpp ($(jlox_cpp_config)) ===="
	@${MAKE} --no-print-directory -C . -f jlox-cpp.make config=$(jlox_cpp_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f jlox-cpp.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   jlox-cpp"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"