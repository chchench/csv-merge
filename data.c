#define MEMORY_SIZE		10typedef char	string[30];typedef string	line[50];extern int		keys[3][2],				numberOfKey;static line		data[MEMORY_SIZE];static int		lineMarker = 0;void	DataInit1(void);	void	InsertLine1(line theLine);Boolean	MatchLine1(line inputLine, line	theLine);void	LookupLine1(int lineNumber, line theLine);void	DataInit1(void){	register	i,				j;		for (i=0; i<MEMORY_SIZE; i++)		for (j=0; j<50; j++)			strcpy(data[i][j],"");}void	InsertLine1(line	theLine){	int		i;	for (i=0; i<50; i++) {/*		if (strcmp(theLine[i],"**********") == 0)			break;		*/		strcpy(data[lineMarker][i],theLine[i]);	}		if (lineMarker == MEMORY_SIZE-1)		lineMarker = 0;	else		lineMarker++;}Boolean	MatchLine1(line inputLine, line	theLine){	int		i,			j;	string	theKeys[3][2];	Boolean	flag;		for (i=0; i<numberOfKey; i++)		ExtractKey(keys[i][1],inputLine,theKeys[i][1]);			for (j=0; j<MEMORY_SIZE; j++) {		flag = TRUE;				for (i=0; i<numberOfKey; i++) {			ExtractKey(keys[i][0],data[j],theKeys[i][0]);			if (strcmp(theKeys[i][0],theKeys[i][1]) != 0) {				flag = FALSE;				break;			}		}				if (flag) {			LookupLine1(j+1,theLine);			return TRUE;		}	}	return FALSE;		}void	LookupLine1(int lineNumber, line theLine){	int		i;		for (i=0; i<50; i++)		strcpy(theLine[i],data[lineNumber-1][i]);}	