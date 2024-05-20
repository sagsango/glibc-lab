# How to see the source code of glibc in gdb
1. Clone the repo : $ git clone https://github.com/sagsango/glibc-lab
2. Run the script : $ ./init-lab.sh
3. Now add your program in lab and attach gdb
   $ cd lab
   $ vim myprogram.c
   $ make
   $ gdb ./myprogram
