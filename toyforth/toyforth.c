#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define TFOBJ_TYPE_INT 0
#define TFOBJ_TYPE_STR 1
#define TFOBJ_TYPE_BOOL 2
#define TFOBJ_TYPE_LIST 3
#define TFOBJ_TYPE_SYMBOL 4

struct {
	int refcount;
	int type;
	union{
		int i;
		struct {
			char *ptr;
			size_t len;
		} str;
		struct {
			struct tfobj **ele;
			size_t len;
		} list;
	};
}tfobj;

typedef struct tfparser {
	char *prg;
	char *p;
}tfparser;

typedef struct tfctx {
	tfobj *stack;
}tfctx;

void *xmalloc(size_t size){
	void* ptr =malloc(size);
	if (ptr==NULL){
		fprintf(stderr,"Out of memory allocating %zu bytes\n",size);
		exit(1);
	}
	return ptr;
}

tfobj *createObject(int type) {
    tfobj *o = xmalloc(sizeof(tfobj));
    o->type = type;
    o->refcount = 1;
}

tfobj *createStringObject(char *s, size_t len) {
    tfobj *o = createObject(TFOBJ_TYPE_STR);
    o->str.ptr = s;
    o->str.len = len;
}

tfobj *createSymbolObject(char *s, size_t len) {
    tfobj *o = *createStringObject(s, len);
    o->type = TFOBJ_TYPE_SYMBOL;
}

tfobj *createIntObject(int i) {
    tfobj *o = createObject(TFOBJ_TYPE_INT);
    o->i = i;
    return o;
}

tfobj *createBoolObject(int i) {
    tfobj *o = createObject(TFOBJ_TYPE_BOOL);
    o->list.ele = NULL;
    o->list.len = 0
    return o;
}


void listPush(tfobj *l,tfobj *ele){
	l->list.ele=realloc(sizeof(tfobj*) *(l->list.len+1));
	l->list.ele[l->list.len]

void parserSpaces(tfparser *parser){
	while(isspace(parser->p[0])) parser->p++;
}

tfobj *parseNumber(tfparser *parser){
	char buf[128];
	char *start = parser->p;
	char *end;

	if (parser->p[0] ==0)
	


tfobj *compile(char *prg){
	tfparser parser;
	parser.prg=prg;
	parser.p=prg;
	
	while(parser.p) {
		tfobj *o;

		parserSpaces(&parser);
		if (parser.p[0]==0)break;
		if(isdigit(parser.p[0])||parser.p[0]=='-'){
			o=parseNumber(&parser);
		}
		else{
			o=NULL;
		}
		if(o==NULL){
			printf("")
	
	}
}

int main(int argc,char **argv){
	if (argc !=2){
		fprintf(stderr,"usage: %s <filename>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1],"r");
	if (fp==NULL){

	}

	fseek(fp,0,SEEK_END);
	long file_size = ftell(fp);
	char *prgtext = xmalloc(file_size +1);
	fseek(fp,0,SEEK_END);
	



	tfobj *prg=compile(prgtext);
	exec (prgtext);
	return 0;
}

