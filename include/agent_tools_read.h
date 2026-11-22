#define _S(x) #x
#define _STR(x) _S(x)
int __path_probe[_STR(__FILE__)[0]];
