.name "ASM_showcase"
.comment " hi Let me show you how it works"

live    %42
ld      21,r1
st      r2,r3

label42:
add     r1,r2,r3
sub     r1,r2,r3

jump_here: and     21,%:label42,r11
or      %255,r1,r2
xor     %-1,r3,r4
zjmp    %:jump_here
ldi     r1,r2,r3
sti     r16,255,%63
fork    %511
lld     42,r9
lldi    r7,r8,r9
lfork   %99
aff     r2
