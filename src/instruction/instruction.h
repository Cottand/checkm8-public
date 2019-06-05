#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <stdint.h>

typedef enum e_instr_type
{
  Data_Proc,
  Mul,
  Data_Trans,
  Branch,
  Halt
} instr_type;

typedef struct s_Data_Proc_Instr
{
  unsigned int cond : 4;
  unsigned int i : 1;
  unsigned int opcode : 4;
  unsigned int s : 1;
  unsigned int rn : 4;
  unsigned int rd : 4;
  unsigned int operand_2 : 12;

} Data_Proc_Instr;

typedef struct s_Mul_Instr
{
  unsigned int cond : 4;
  unsigned int a : 1;
  unsigned int s : 1;
  unsigned int rd : 4;
  unsigned int rn : 4;
  unsigned int rs : 4;
  unsigned int rm : 4;
} Mul_Instr;

typedef struct s_Data_Trans_Instr
{
  unsigned int cond : 4;
  unsigned int i : 1;
  unsigned int p : 1;
  unsigned int u : 1;
  unsigned int l : 1;
  unsigned int rn : 4;
  unsigned int rd : 4;
  unsigned int offset: 12;
} Data_Trans_Instr;

typedef struct s_Branch_Instr
{
  unsigned int cond : 4;
  signed int offset : 24;
} Branch_Instr;

typedef struct s_Instr
{
  instr_type type;

  Data_Proc_Instr *data_proc_instr;
  Mul_Instr *mul_instr;
  Data_Trans_Instr *data_trans_instr;
  Branch_Instr *branch_instr;
} Instr;

void instr_init(Instr *instr);
void instr_free(Instr *instr);

uint32_t instr_to_uint32(Instr *instr);
uint32_t data_proc_instr_to_uint32(Data_Proc_Instr *instr);
uint32_t mul_instr_to_uint32(Mul_Instr *instr);
uint32_t data_trans_instr_to_uint32(Data_Trans_Instr *instr);
uint32_t branch_instr_to_uint32(Branch_Instr *instr);
uint32_t halt_instr_to_uint32();

#endif /* INSTRUCTION_H_ */