#ifndef __AMARA__BISON__SYNTAX_TREE_NODE__H__
#define __AMARA__BISON__SYNTAX_TREE_NODE__H__

#define BISON_NODE_TYPE_INVALID  0x00
#define BISON_NODE_TYPE_TEXT     0x01
#define BISON_NODE_TYPE_NATURAL  0x02
#define BISON_NODE_TYPE_INTEGER  0x03
#define BISON_NODE_TYPE_RATIONAL 0x04
#define BISON_NODE_TYPE_ERRORED  0xFF

typedef struct text_subnode {
	char * value;
} text_subnode;

typedef struct natural_subnode {
	char * raw;
} natural_subnode;

typedef struct integer_subnode {
	char * raw;
} integer_subnode;

typedef struct rational_subnode {
	char * raw;
} rational_subnode;

/*   `b_node` for 'Bison node'. */
typedef struct b_node {
	uint_fast8_t type;
	text_subnode * text;
	natural_subnode * natural;
	integer_subnode * integer;
	rational_subnode * rational;
} b_node;

#endif
