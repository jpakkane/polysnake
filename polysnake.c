/*
 * Copyright (C) 2017 Jussi Pakkanen.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of version 3, or (at your option) any later version,
 * of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Python.h>
#include <string.h>

static PyObject* generate(PyObject *self, PyObject *args) {
    return Py_BuildValue("y", "standin");
}

static PyMethodDef TachyonMethods[] = {
    {"generate",  generate, METH_VARARGS,
     "Create polyglot text."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef polysnakemodule = {
   PyModuleDef_HEAD_INIT,
   "polysnake",
   NULL,
   -1,
   TachyonMethods
};

PyMODINIT_FUNC PyInit_polysnake(void) {
    return PyModule_Create(&polysnakemodule);
}
