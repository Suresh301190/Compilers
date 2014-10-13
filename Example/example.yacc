program	: CLASS PROGRAM	OB method_decls CB   {	Init (&$$, "program");
									$$->firstChild = $4;
									PrintTree2($$);
								}
	;

method_decls :   method_decls method_decl   {   Init(&$$, "method_decls");
												if($1){
													$$->firstChild = $1;
													$1->nextSibling = $2;
												}
												else
													$$->firstChild = $2;
											}
	|       {   $$ = NULL;
			}
	;

method_decl :   VOID ID OP args CP block    {   Init(&$$, "bool");
												$$->firstChild = $2;
												if($4) {
													$2->nextSibling = $4;
													$4->nextSibling = $6;
												}
												else
													$2->nextSibling = $6;
											}
	|   INT ID OP args CP block {   Init(&$$, "int");
									$$->firstChild = $2;
									if($4) {
										$2->nextSibling = $4;
										$4->nextSibling = $6;
									}
									else
										$2->nextSibling = $6;
								}
	|   BOOL ID OP args CP block    {   Init(&$$, "bool");
										$$->firstChild = $2;
										if($4) {
											$2->nextSibling = $4;
											$4->nextSibling = $6;
										}
										else
											$2->nextSibling = $6;
									}
	;

args    :   arg args1   {   Init(&$$, "args");
							$$->firstChild = $1;
							$1->nextSibling = $2;
						}
	|       {   $$ = NULL;
			}
	;

args1   :   COMMA arg args1 {   Init(&$$, "args");
								$$->firstChild = $2;
								$2->nextSibling = $3;
							}
	|       {   $$ = NULL;
			}
	;

arg :   BOOL ID {   Init(&$$, "bool");
					$$->firstChild = $2;
				}
	|   INT ID  {   Init(&$$, "int");
					$$->firstChild = $2;
				}
	;

block   :   OB var_decls stmts CB   {   Init(&$$, "block");
										$$->firstChild = $2;
									}
	;

var_decls   :   var_decls var_decl  {   Init(&$$, "var_decls");
										if($1){
											$$->firstChild = $1;
											$1->nextSibling = $2;
										}
										else
											$$->firstChild = $2;
									}
	|       {   $$ = NULL;
			}
	;

var_decl    :   arg vars SEMCOL {   Init(&$$, "var_decl");
									$$->firstChild = $1;
									$1->nextSibling = $2;
								}
	;

vars    :   COMMA var vars  {   Init(&$$, "var");
								$$->firstChild = $2;
								$2->nextSibling = $3;
							}
	|       {   $$ = NULL;
			}
	;

var :   ID  {   $$ = $1;
			}
	;
