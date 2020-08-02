//compare string
bool comstring(char *s1,char *s2){
	int i=0;
	for(i;s1[i]==s2[i]&&s1[i]!='\n'&&s1[i]!='\n';i++);
	if(s1[i]=='\n'&&s2[i]!='\n')
		return -1;
	else if(s1[i]!='\n'&&s2[i]=='\n')
		return 1;
	else if(s1[i]=='\n'&&s2[i]=='\n')
		return 0;
	else return s1[i]-s2[i]
}

bool find(char *s3, char a){
	int i=0;
	while(s3[i]!='\n'&&s3[i]!=a)
		i++;
	if(s3[i]=='\n')
		return 0;
	else return 1;
}