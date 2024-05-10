#!/bin/bash
ch=0
while [ $ch -ne 6 ]
do

echo -e 'Enter Your choice \n1:Create Address Book \n2:Insert Record\n3:Delete Record\n4:Display Record\n5:Modify Recod\n6:Exit'


read ch


case $ch in
	  1)
	  echo "Enter Name of Adress Book"
	  read file
	  touch $file
	  	
	  ;;
	  2) 
	  
	  echo "Enter employee Id :"
	  read empid
	  
	  echo "Enter employee Name :"
	  read empname
	  
	  echo "Enter employee Address:"
	  read empadd
	  
	  echo -e $empid '\t\t '$empname  '\t\t' $empadd >> $file
	  
	 ;;
	 
	 3)
	 
	 echo "Enter Id of Record to be Deleted"
	 read empid1
	 
	 sed -i '/'$empid1'/d' $file
	 ;;
	 4)
	 
	 echo -e 'EmpID \t\t Name  \t\t Address'
	 cat $file
	 
	 
	 ;;
	 5)
	 echo "On which Basis You Want to Modify"
	 echo -e "1:ID \n2:Name \n3:Address"
	 read mod
	 
	 case $mod in 
	 1)
	 echo "Enter Old ID"
	 read oldId
	 
	 no=`grep -n $oldId $file | cut -c 1` 	 
	 
	       echo "Which Feature do You want to modify"
	       echo -e "1:Id \n2:Name \n3:Address"
	       read f
	       
	       if [ $f -eq 1 ]
	       then
	 	echo "Enter New ID"
	        read newId
		
		
		cat $file | sed -i "$no s/$oldId/$newId/" $file
		
		elif [ $f -eq 2 ]
		then 
		 echo "Enter Old name"
		 read oldname
	 
	 	echo "Enter New name"
	        read newname
		
		
		cat $file | sed -i "$no s/$oldname/$newname/" $file
		
		elif [ $f -eq 3 ]
		then
		 echo "Enter Old Address"
		 read oldadd
	 
	 	echo "Enter New Address"
	        read newadd
		
		 
		cat $file | sed -i "$no s/$oldadd/$newadd/" $file

	        else 
	        echo "Wrong choice"
	        
	        fi
		
		


	 ;;
	 2)
	 echo "Enter Old name"
	 read oldname
	 
	 	
		no=`grep -n $oldname $file| cut -c 1` 	 
		
		
		echo "Which Feature do You want to modify"
	       echo -e "1:Id \n2:Name \n3:Address"
	       read f
	       
	       if [ $f -eq 1 ]
	       then
	       
	 echo "Enter Old ID"
	 read oldId
	 	echo "Enter New ID"
	        read newId
		
		 
		cat $file | sed -i "$no s/$oldId/$newId/" $file
		
		elif [ $f -eq 2 ]
		then 
		
	 	echo "Enter New name"
	        read newname
		
		 
		cat $file | sed -i "$no s/$oldname/$newname/" $file
		
		elif [ $f -eq 3 ]
		then
		 echo "Enter Old Address"
		 read oldadd
	 
	 	echo "Enter New Address"
	        read newadd
		
		 
		cat $file | sed -i "$no s/$oldadd/$newadd/" $file

	        else 
	        echo "Wrong choice"
	        
	        fi

	 
	 ;;
	 
	 3)
	 echo "Enter Old Address"
	 read oldadd
	 
	 	
		no=`grep -n $oldadd $file | cut -c 1` 
		
		echo "Which Feature do You want to modify"
	       echo -e "1:Id \n2:Name \n3:Address"
	       read f
	       
	       if [ $f -eq 1 ]
	       then
	       
	 echo "Enter Old ID"
	 read oldId
	 	echo "Enter New ID"
	        read newId
		
		 
		cat $file | sed -i "$no s/$oldId/$newId/" $file
		
		elif [ $f -eq 2 ]
		then 
		
		 echo "Enter Old Name"
		 read oldname
	 
	 	echo "Enter New name"
	        read newname
		
		 
		cat $file| sed -i "$no s/$oldname/$newname/" $file
		
		elif [ $f -eq 3 ]
		then
	 	echo "Enter New Address"
	        read newadd
		
		 
		cat $file | sed -i "$no s/$oldadd/$newadd/" $file

	        else 
	        echo "Wrong choice"
	        
	        fi
	 
		 
	 ;; 
	 esac
esac	
done 
