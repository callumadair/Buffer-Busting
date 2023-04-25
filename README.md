# Just Some Nice, Totally Safe Bits of Code that are definitely not bad! :)
Definitely don't compile and run these as executables, this is just for research purposes.



# Steps

You will first need to access the VM:

```sh
ssh -i /Downloads/mySSHKey.pem azureuser@10.0.0.249
```

## C Buffer overflow

1. Compile the C code using the gcc compiler, for example: `gcc overflow.c -o overflow`
2. Run the overflow, for example: `./overflow`
