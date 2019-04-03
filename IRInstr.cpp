#include "IRInstr.h"
#include "BasicBlock.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op_, Type t_, vector<string> params_) {
	bb = bb_; 
	op = op_;
	t = t_;
	params = params_;
}

void IRInstr::genererCodeAssembleur(ostream &o) {
	switch (op) {
		case (ldconst) : {
			// récuperer offset du premier argument et le mettre après le -
			int offsetVar = bb->cfg->getOffsetFromSymbolTable(params[0]);
			o << "movq $" << params[1] << ", " << to_string(offsetVar) << "(%rbp)\r\n";
			break;
		}
		case (add) : {
			int offset1 = bb->cfg->getOffsetFromSymbolTable(params[1]);
			int offset2 = bb->cfg->getOffsetFromSymbolTable(params[2]);
			int offset3 = bb->cfg->getOffsetFromSymbolTable(params[0]);

			o << "movq " << to_string(offset1) << "(%rbp), %rax\r\n";
			o << "addq " << to_string(offset2) << "(%rbp), %rax\r\n";
			o << "movq %rax, " << to_string(offset3) << "(%rbp)\r\n";
			break;
		}
		case (sub) : {
			int offset1 = bb->cfg->getOffsetFromSymbolTable(params[1]);
			int offset2 = bb->cfg->getOffsetFromSymbolTable(params[2]);
			int offset3 = bb->cfg->getOffsetFromSymbolTable(params[0]);

			o << "movq " << to_string(offset1) << "(%rbp), %rax\r\n";
			o << "subq " << to_string(offset2) << "(%rbp), %rax\r\n";
			o << "movq %rax, " << to_string(offset3) << "(%rbp)\r\n";
			break;
		}
		case (mul) : {
			int offset1 = bb->cfg->getOffsetFromSymbolTable(params[1]);
			int offset2 = bb->cfg->getOffsetFromSymbolTable(params[2]);
			int offset3 = bb->cfg->getOffsetFromSymbolTable(params[0]);

			o << "movq " << to_string(offset1) << "(%rbp), %rax\r\n";
			o << "imulq " << to_string(offset2) << "(%rbp), %rax\r\n";
			o << "movq %rax, " << to_string(offset3) << "(%rbp)\r\n";
			break;
		}
		case (rmem) :
			break;
		case (wmem) : {
			int offset = bb->cfg->getOffsetFromSymbolTable(params[1]);
			if (!params[0].compare("!rax")) {
				o << "movq " << to_string(offset) << "(%rbp), %rax\r\n";
			} else {
				int offsetParams0 = bb->cfg->getOffsetFromSymbolTable(params[0]);
				o << "movq " << to_string(offset) << "(%rbp), %rax\r\n";	
				o << "movq %rax, " << to_string(offsetParams0) << "(%rbp)\r\n";
			}
			break;
		}
		case (call) :{
			if(!params[1].compare("putchar")){
				int offsetParam = bb->cfg->getOffsetFromSymbolTable(params[2]);
				int offsetDest = bb->cfg->getOffsetFromSymbolTable(params[0]);
				o << "movq " << to_string(offsetParam) << "(%rbp), %rdi\r\n";
				o << "call putchar\r\n";
				o << "movq %rax, " << to_string(offsetDest) << "(%rbp)\r\n";
			}
			else{
				for (int i=2; i<params.size(); i++) {
					int offsetParam = bb->cfg->getOffsetFromSymbolTable(params[i]);
					switch(i) {
						case 2: {
							o << "movq " << to_string(offsetParam) << "(%rbp), %rdi\r\n";
							break;
						}
						case 3: {
							o << "movq " << to_string(offsetParam) << "(%rbp), %rsi\r\n";
							break;
						}
						case 4: {
							o << "movq " << to_string(offsetParam) << "(%rbp), %rdx\r\n";
							break;
						}
						case 5: {
							o << "movq " << to_string(offsetParam) << "(%rbp), %rcx\r\n";
							break;						
						}
						case 6: {
							o << "movq " << to_string(offsetParam) << "(%rbp), %r8\r\n";
							break;						
						}
						case 7: {
							o << "movq " << to_string(offsetParam) << "(%rbp), %r9\r\n";	
							break;
						}
						default:
							cerr << "Trop de paramètres dans la fonction, non géré actuellement" << endl;
							break;	
					}				
				}
				
				int offsetDest = bb->cfg->getOffsetFromSymbolTable(params[0]);
				
				o << "call " << params[1] << "\r\n";
				o << "movq %rax, " << to_string(offsetDest) << "(%rbp)\r\n";
			}
			break;
		}
		case (cmp_eq) :
			break;
		case (cmp_lt) :
			break;
		case (cmp_le) :
			break;
		default: {
			break;
		}
	}
}
