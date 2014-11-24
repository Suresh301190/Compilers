char* paramRegs[] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
char strings[2048] = {0};

char* GetVal(struct symbol* s) {
	static char v[256];
	static int strId = 0;


	if (s->sType == int_const) {
		sprintf(v, "$%s", s->name);
	}
	else if (s->sType == vartmp) {
		sprintf(v, "-%d(%%rbp)", s->offset);
	}  else if (s->sType == str_const) {
                //add to a list of strings to be emitted later
                strId ++;
                char str[256];
                sprintf(str, "format%d: .asciz %s\n", strId, s->name);
                strcat(strings, str);
                sprintf(v, "$format%d", strId);
        } else if (s->sType == labelvar) {
		sprintf(v, "%s_1", s->name);
	}
	return v;
}//GetVal

void EmitMain () {
        int counter = 0;

        printf(".globl main\n");
        printf(".text\n");
        printf("main:\n");
        printf("L0_1: push %%rbp\n");
        printf("L0_2: movq %%rsp, %%rbp\n");

        //make space for local vars and temporaries
        //the offset required is stored in src1 field
        //and is 16B aligned
        printf("L0_3: subq $%d, %%rsp\n", offset);



}//EmitMain

void EmitRet(struct quadtab* q) {
        int counter = 0;


        //reclaim storage space for local vars and temporaries
        printf("L%d_%d: addq $%d, %%rsp\n", q->idx, ++counter, offset);

        //restore rbp and return
        printf("L%d_%d: pop %%rbp\n", q->idx, ++counter);
        printf("L%d_%d: ret\n", q->idx, ++counter);

 }//EmitRet


void EmitAssign(struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));
	printf("L%d_%d: movq %%rax, %s\n", q->idx, ++counter, GetVal(q->dst));

}//EmitAssign

void EmitAdd (struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));
	printf("L%d_%d: movq %s, %%rbx\n", q->idx, ++counter, GetVal(q->src2));
	printf("L%d_%d: addq %%rbx, %%rax\n", q->idx, ++counter);
	printf("L%d_%d: movq %%rax, %s\n", q->idx, ++counter, GetVal(q->dst));

}//EmitAdd

void EmitSub (struct quadtab* q) {
        int counter = 0;
        printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));
        printf("L%d_%d: movq %s, %%rbx\n", q->idx, ++counter, GetVal(q->src2));
        printf("L%d_%d: sub %%rbx, %%rax\n", q->idx, ++counter);
        printf("L%d_%d: mov %%rax, %s\n", q->idx, ++counter, GetVal(q->dst));

}//EmitSub



void EmitMul (struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));
	printf("L%d_%d: movq %s, %%rbx\n", q->idx, ++counter, GetVal(q->src2));
	printf("L%d_%d: mulq %%rbx\n", q->idx, ++counter);
	printf("L%d_%d: movq %%rax, %s\n", q->idx, ++counter, GetVal(q->dst));

}//EmitMul



void EmitLT (struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));
	printf("L%d_%d: movq %s, %%rbx\n", q->idx, ++counter, GetVal(q->src2));

	printf("L%d_%d: cmp %%rbx, %%rax\n", q->idx, ++counter);
	printf("L%d_%d: jl L%d_%d\n", q->idx, ++counter, q->idx, counter + 4);
	printf("L%d_%d: movq $0, %%rax\n", q->idx, ++counter);
	printf("L%d_%d: jmp L%d_%d\n", q->idx, ++counter, q->idx, counter + 3);
	printf("L%d_%d: movq $1, %%rax\n", q->idx, ++counter);

	printf("L%d_%d: movq %%rax, %s\n", q->idx, ++counter, GetVal(q->dst));

}//EmitLT




void EmitIf (struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));


	printf("L%d_%d: cmp $0, %%rax\n", q->idx, ++counter);
	printf("L%d_%d: jne %s\n", q->idx, ++counter, GetVal(q->dst));




}//EmitIf

void EmitIfFalse (struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: movq %s, %%rax\n", q->idx, ++counter, GetVal(q->src1));


	printf("L%d_%d: cmp $0, %%rax\n", q->idx, ++counter);
	printf("L%d_%d: je %s\n", q->idx, ++counter, GetVal(q->dst));




}//EmitIfFalse

void EmitGoto (struct quadtab* q) {
	int counter = 0;
	printf("L%d_%d: jmp %s\n", q->idx, ++counter, GetVal(q->dst));
}//EmitJmp


void HandleParams (struct quadtab** q) {
        int counter = 0;
        struct quadtab* qt = *q;

        int np = 0;
        while (strcmp(qt->opcode, "param") == 0) {

                if (np > 5) assert (0);
                printf("L%d_%d: movq %s, %s\n", qt->idx, ++counter, GetVal(qt->dst), paramRegs[np]);
                np ++;
                *q = qt;
                qt = qt->next;

		if (strcmp(qt->opcode, "param") == 0) {
	                printf("\n#");
        	        PrintQuad(qt);
                	printf("\n");

		}
        }




}//Handle Params

void EmitCall(struct quadtab* q) {
        int counter = 0;

        q->src1->name[strlen(q->src1->name) - 1] = 0;
        printf("L%d_%d: call %s\n", q->idx, ++counter, &(q->src1->name[1]));
        q->src1->name[strlen(q->src1->name)] = '"';
}//EmitCall



void EmitX86Code () {

	EmitMain();

	//skip quads until first function
	struct quadtab* fq = NULL; //remembers which function is being processed
	struct quadtab* q = quads; //iterates over quadruples


	while (q != NULL)
	{
		printf("\n#");
		if(!PrintQuad(q)){
			q = q->next;
			continue;
		}
		printf("\n");
		if (strcmp(q->opcode, "=") == 0) { EmitAssign(q); }
		else if (strcmp(q->opcode, "+") == 0) { EmitAdd(q); }
		else if (strcmp(q->opcode, "-") == 0) { EmitSub(q); }
		else if (strcmp(q->opcode, "*") == 0) { EmitMul(q); }
		else if (strcmp(q->opcode, "<") == 0) { EmitLT(q); }
		else if (strcmp(q->opcode, "if") == 0) { EmitIf(q); }
		else if (strcmp(q->opcode, "ifFalse") == 0) { EmitIfFalse(q); }
		else if (strcmp(q->opcode, "goto") == 0) { EmitGoto(q); }
		else if (strcmp(q->opcode, "param") == 0) { HandleParams(&q); }
                else if (strcmp(q->opcode, "call") == 0) { EmitCall(q); }
		else if (strcmp(q->opcode, "halt") == 0) { EmitRet(q); }

		q = q->next;
	}

	printf("%s\n", strings);
}//EmitX86Code
