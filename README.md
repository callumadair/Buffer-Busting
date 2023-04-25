# Just Some Nice, Totally Safe Bits of Code that are definitely not bad! :)
Definitely don't compile and run these as executables, this is just for research purposes.



# Steps

First, download the private ssh key that should have been provided to you.

Using the provided ssh key you will first need to access the VM:

```sh
ssh -i /Downloads/mySSHKey.pem azureuser@10.0.0.249
```

Now install the build-essential packages including the GNU C Compiler (GCC) and GNU Debugger (GDB):

```sh
sudo apt-get install build-essential
```

Then disable address space layout randomisation:

```sh
sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
```

Then install the rust compiler, rustup rust installer and version manager, and cargo package manager from the rust website:

```sh
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Now install git:

```sh
sudo apt install git-all
```

Then clone this repository in a directory of your choice:

```sh
git clone https://github.com/callumadair/Buffer-Busting.git
```
Now navigate to the source code files and perform the following steps:

## C Buffer overflow

1. Compile the C code using the gcc compiler excluding stack protections such as canaries, for example: `gcc overflow.c -o overflow -fno-stack-protector`
2. Now using gdb, capture the execution of the program: `gdb ./overflow`
3. Now disassamble the program: `disas main`
3. Locate the call to `strcpy` then add a breakpoint so that we can capture the state of the memory addresses, for example: `break *0000...`
4. Now , run the program with `r`
5. View the memory addresses using `x/100wx $esp`
6. Continue the execution: `c`
7. View the memory addresses again: `x/100wx $esp`

## Rust Unsafe Overflow

1. Compile the rust code using the rust compiler, for example: `rustc overflow_unsafe.rs`
2. Run the overflow, for example: `./overflow_unsafe`
