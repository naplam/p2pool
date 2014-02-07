from distutils.core import setup, Extension

max_sha3_module = Extension('max_sha3',
                               sources = ['sha3module.c', 
                                          'keccak.c'],
                               include_dirs=['.'])

setup (name = 'max_sha3',
       version = '1.0',
       description = 'Bindings for SHA3 proof of work used by Maxcoin',
       ext_modules = [max_sha3_module])
