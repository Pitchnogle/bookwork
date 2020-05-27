# Chapter 2

## Build a distribution file

```
$ python3 setup.py sdist
running sdist
running check
warning: sdist: manifest template 'MANIFEST.in' does not exist (using default file list)

warning: sdist: standard file not found: should have one of README, README.txt

writing manifest file 'MANIFEST'
creating nester-1.0.0
making hard links in nester-1.0.0...
hard linking nester.py -> nester-1.0.0
hard linking setup.py -> nester-1.0.0
creating dist
Creating tar archive
removing 'nester-1.0.0' (and everything under it)
```

## Install the distribution into local copy of Python

```
$ sudo python3 setup.py install
[sudo] password for username:
running install
running build
running build_py
creating build
creating build/lib
copying nester.py -> build/lib
running install_lib
copying build/lib/nester.py -> /usr/local/lib/python3.6/dist-packages
byte-compiling /usr/local/lib/python3.6/dist-packages/nester.py to nester.cpython-36.pyc
running install_egg_info
Writing /usr/local/lib/python3.6/dist-packages/nester-1.0.0.egg-info
```
