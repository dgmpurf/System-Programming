# CPTS360 --KCWang
# Creating and build system by C/C++
1. Fill in NAMEs,IDs. Send back to TA before 4-24-2020 to schedule DEMO time
2. DEMO with TA at scheduled time AND submit a ZIP file of YOUR project to TA
3. KCW will schedule interview time (via ZOOM) seperately AFTER you DEMO to TA
4. Download disk1,disk2,disk3.1,disk3.2, dif2 from samples/PROJECT/ directory 

LEVEL-1: Use disk1                                            55 %
   COMMANDS                    EXPECTED RESULTS           OBSERVED & comments
------------------      ------------------------------  ----------------------
startup & menu:          start up, show commands menu   yes
ls                       show contents of / directory   yes

mkdir /a ;     ls        show DIR /a exits; ls works    yes

mkdir /a/b ;   ls /a     make dir with pathname         yes

cd    /a/b ;   pwd       cd to a pathname, show CWD     yes

cd    ../../ ; pwd       cd upward, show CWD            yes

creat f1     ; ls        creat file, show f1 is a file  yes

link  f1 f2;   ls        hard link, both linkCount=2    yes

unlink   f1;   ls        unlink f1; f2 linkCount=1      no(but f2 works)

symlink f2 f3; ls        symlink; ls show f3 -> f2      yes

rmdir /a/b;    ls        rmdir and show results         yes(sometimes not)
  
LEVEL-2: Use disk2: (file1,tiny,small,large,huge)             25 %
------------------        ---------------------------   -----------------------
cat large; cat huge       show contents to LAST LINE
                           === END OF huge FILE ===   yes

cp  large newlarge; ls    show they are SAME size     yes

cp  huge  newhuge ; ls    show they are SAME size     yes

              MUST DO THIS: exit YOUR project; 
(In Linux): dif2          MUST not show any lines     yes

============ IF can not do cat, cp: TRY to do these for LEVEL2 ================
open  small 0;   pfd      show fd=0 opened for R      _________________________

read 0 20;       pfd      show 20 chars read          _________________________

open file1 1;    pfd      show fd=1 opened for W      _________________________

write 1 "abcde"; ls       show file1 size=5           _________________________

close 1; pfd              show fd=1 is closed         _________________________

LEVEL-3: start with disk3.1;   MOUNT disk3.2                  20 %
-------------------   ----------------------------  ----------------------------
mount disk3.2 /mnt;       mount disk3.2 on /mnt      yes

ls /mnt                   contents of disk3.2        yes

cd /mnt/DIR1; pwd         show CWD is /mnt/DIR1      yes

mkdir ABC; ls             show ABC exits             yes

cd ../../;    pwd         show CWD=/                 yes

Switch to P1; rmdir dir1; unlink file1 : not owner   No (unlink file1 not work, others good)
