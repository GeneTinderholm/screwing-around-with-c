run: exe lib_one lib_two
	./main
exe:
	export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:~/c/further_examples/dynamic_loading" && gcc -o main dyn_load.c -ldl
lib_one:
	gcc -g -fPIC dyn_lib.c -shared -o libdynlib.so
lib_two:
	gcc -g -fPIC dyn_lib_two.c -shared -o libdynlibtwo.so
clean:
	rm *.so
	rm main
