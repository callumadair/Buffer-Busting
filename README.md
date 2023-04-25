# Just Some Nice, Totally Safe Bits of Code that are definitely not bad! :)
Definitely don't compile and run these as executables, this is just for research purposes.



# Steps

You will first need to access the VM:

```sh
ssh -i /Downloads/mySSHKey.pem azureuser@10.0.0.249
```

Then install the rust compiler, rustup rust installer and version manager, and cargo package manager from the rust website:

```sh
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

## C Buffer overflow

1. Compile the C code using the gcc compiler, for example: `gcc overflow.c -o overflow`
2. Run the overflow, for example: `./overflow`

## Rust Unsafe Overflow

1. Compile the rust code using the rust compiler, for example: `rustc overflow_unsafe.rs`
2. Run the overflow, for example: `./overflow_unsafe`
