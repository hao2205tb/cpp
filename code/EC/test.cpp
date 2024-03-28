#define shift(register) ((register)>>8)
#define clear(register, index) (register)&(~(1<<(index))) 