# Rux-perl
  Rux-perl is a project that supports Perl on Ruxos
### Easy run:
##### Step1：
Run [Ruxos](https://github.com/syswonder/ruxos)
##### Step2:
  Go to ruxos Root dir and run:
  
```bash
bash
git clone https://github.com/Miochyann/rux-perl.git ./apps/c/rux-perl
make A=apps/c/rux-perl ARCH=aarch64 V9P=y NET=y MUSL=y LOG=info SMP=1 run
```

##### Perl test
  Because Ruxos is not support `fork()` now, so I used another way to run the test program.
  if you want to run the test program, Go to ruxos Root dir and run:
```bash
sh apps/c/rux-perl/test_perl.sh
```