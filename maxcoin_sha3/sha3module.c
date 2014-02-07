#include <Python.h>

//#include "sha3.h"

#include "sph_keccak.h"

static PyObject *sha3_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
    PyStringObject *input;
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

//printf(" <<KECCAK>> ");

//    crypto_hash((char*)output, (unsigned char *)PyString_AsString((PyObject*) input), (unsigned long long)PyString_Size((PyObject*)input));

{
    sph_keccak256_context ctx_keccak;
    static unsigned char pblank[1];

    sph_keccak256_init(&ctx_keccak);
	unsigned long long size=(unsigned long long)PyString_Size((PyObject*)input);
    sph_keccak256 (&ctx_keccak, (size==0)? pblank : (unsigned char *)PyString_AsString((PyObject*) input), size); //(pend - pbegin) * sizeof(pbegin[0]));
    sph_keccak256_close(&ctx_keccak, (void*)output);
}

    Py_DECREF(input);
    value = Py_BuildValue("s#", output, 32);
    PyMem_Free(output);
    return value;
}

static PyMethodDef ScryptMethods[] = {
    { "getPoWHash", sha3_getpowhash, METH_VARARGS, "Returns the proof of work hash using SHA3" },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initmax_sha3(void) {
    (void) Py_InitModule("max_sha3", ScryptMethods);
}
