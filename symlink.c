/*********** symlink.c file ****************/

extern MINODE minode[NMINODE];
extern MINODE *root;
extern PROC   proc[NPROC], *running;

extern char   gpath[256];
extern char   *name[64];
extern int    n;

extern int    fd, dev;
extern int    nblocks, ninodes, bmap, imap, inode_start;
extern char   line[256], cmd[32], pathname[256], pathname2[256];

int symlink()
{
	int ino, i, link_ino, pino;
	char temp[256], temp2[256], tempOld[256], parent[256], child[256];
	char oldName[256];

	MINODE *mip;
	MINODE *pmip;
	MINODE *link_mip;

	INODE *link_ip;

	strcpy(tempOld, pathname);
	strcpy(oldName, basename(tempOld));
    //(1)verify old name
	//get inode of old file
	ino = getino(pathname);
	mip = iget(dev, ino);

    //make sure pathname is less than 60. (84 bytes - 24 unused bytes after INODE i_block[]
	if(strlen(pathname) > 60)
	{
		printf("name too long.\n");
		return -1;
	}

    //check if old file exists
	if(!mip)
	{
		printf("%s does not exist\n", pathname);
		return -1;
	}

	//get parent and child of old file pathname
	strcpy(temp, pathname2);
	strcpy(parent, dirname(temp));
    strcpy(temp2, pathname);
	strcpy(child, basename(pathname2));

	printf("parent is %s,  child is %s\n", parent, child);

	pino = getino(parent);
	pmip = iget(dev, pino);

	if(!pmip)
	{
		printf("can't get parent mip.\n");
		return -1;
	}

	if(!S_ISDIR(pmip->INODE.i_mode))
	{
	 	printf("parent is not a directory.\n");
	 	return -1;
	}

	if(getino(child) > 0)
	{
		printf("%s already exists\n", child);
		return -1;
	}

	link_ino = my_creat(pmip, child);
	//gets the newfile minode to set it's variables
	link_mip = iget(dev, link_ino);
	//link_ip = &link_mip->INODE;

	//set the link mode
	link_mip->INODE.i_mode = 0120000;
    strcpy((char*)(link_mip->INODE.i_block), pathname);  //set name file is linked to
	//set the link size, which is the size of the oldfiles name
	link_mip->INODE.i_size = strlen(oldName);

	link_mip->dirty = 1;
	iput(link_mip);
	iput(mip);
}


char *read_link(char link_name[]) {
	int ino = getino(link_name);
	MINODE * mip = iget(dev, ino);

	if (!S_ISLNK(mip->INODE.i_mode)) {
		printf("  read_link(): error: %s is not symlink\n", link_name);
		iput(mip);
        return 0;
	}

	return (char *)mip->INODE.i_block;
}
