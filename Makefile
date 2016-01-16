bin/png: src/main.c
	mkdir -p bin
	gcc $< -o $@
