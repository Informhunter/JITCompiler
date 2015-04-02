test-time:
	gcc test.c parser/parser.c compiler/compiler.c compiler/bytearray/bytearray.c compiler/opcodes/opcodes.c tree/tree.c -otest.exe -Werror -I"."
test-values:
	gcc testvalues.c parser/parser.c compiler/compiler.c compiler/bytearray/bytearray.c compiler/opcodes/opcodes.c tree/tree.c -otestvalues.exe -Werror -I"."