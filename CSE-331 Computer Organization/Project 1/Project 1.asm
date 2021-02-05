.data
myArray:.space 100
screenMessage:.asciiz "Enter size of array:"
screenMessage2:.asciiz "Enter target number:"
screenMessage3:.asciiz "Enter elements of array:"
screenMessage4:.asciiz "Possible!\n"
screenMessage5: .asciiz "Not Possible!\n"
.text
main:
	li $v0,4
	la $a0,screenMessage
	syscall
	
	li $v0,5
	syscall	#cin >> arraySize
	move $a1,$v0 #arraySize parameter
	
	li $v0,4
	la $a0,screenMessage2
	syscall
	
	li $v0,5
	syscall #cin >> num
	move $a2,$v0 #num parameter
	
	li $v0,4
	la $a0,screenMessage3 
	syscall
	jal addElementToArray
	
	la $a0,myArray #Array address parameter
	li $v0,1
	jal CheckSumPossibility #call CheckSumPossibility(num,arr,arraysize)
	
	add  $t4,$zero,$v0 #return_val = CheckSumPossibility(num,arr,arraySize)
	bne $t4,$zero,possible #if (return_val == 0)
	li $v0,4
	la $a0,screenMessage5 
	syscall # cout << "Possible" << endl;

	possible:
		bne $t4,1,program_exit # if(return_val == 1)
		li $v0,4 
		la $a0,screenMessage4
		syscall  # cout << "Possible" << endl;
	
	#Exit
	program_exit:
		li $v0,10
		syscall
	
addElementToArray:
    beq $t2,$a1,exit # i <arraySize
    addi,$t2,$t2,1 # i++   
    
    li $v0,5
    syscall 
    sw $v0,myArray($t0) # cin >> arr[i] 
    add $t0,$t0,4
    j addElementToArray

exit:
    jr $ra
 #--------------------------------------
 #CheckSumPossibility Function
 CheckSumPossibility:
 	addi $t0,$zero,1
 	sllv  $t1,$t0,$a1 # all_subset = 1 << size
 	addi $t2,$zero,0 #i =0
 	first_loop:
 	beq $t2,$t1,first_loop_exit # i= 0 ; i<all_subset
 	
 	addi $t3,$zero,0 #sums = 0
 	addi $t4,$zero,0 #j= 0
 	second_loop:
 	beq $t4,$a1,second_loop_exit # j= 0 ; j < size
 	
 	sllv  $t5,$t0,$t4 # $t5 = 1 <<j
 	and $t6,$t2,$t5 # i & (1<<j)
 	beq $t6,$zero,exit_if # if(i & (1<<j)) 
	add $s1,$zero,$t4 #s1=j
	sll $s1,$s1,2 #s1=s1*4
	add $s2,$s1,$a0 #s2 = >adress of j
	lw $s3,0($s2) #s3 = arr[j]
	add $t3,$t3,$s3 #sums+=arr[j]
 	exit_if:
 	addi $t4,$t4,1 # j++
 	j second_loop
 	second_loop_exit:
 	bne $t3,$a2,exit_if_2 # if(sums == num)
 	li $v0,1 #return 1
 	j exit_function
 	exit_if_2:
 	addi $t2,$t2,1 #i++
 	j first_loop
 	first_loop_exit:li $v0,0 #return 0
 	exit_function:jr $ra
