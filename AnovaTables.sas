FILENAME REFFILE '/folders/myfolders/P2_Dataset3.xlsx';

PROC IMPORT DATAFILE=REFFILE
	DBMS=XLSX
	OUT=Bowlers;
	GETNAMES=YES;
RUN;

PROC CONTENTS DATA=Bowlers; RUN;


proc means data=Bowlers;
Run;

proc print data=Bowlers;
run;
/* Summary statistics by bowler; Checking means  */
proc means data=Bowlers (Drop=GameNum);
class Bowler;
run;
/* View Summary Statistics
Normality Check by Treatment Group */
PROC UNIVARIATE DATA = Bowlers NORMAL;
	BY Bowler;
	VAR Score;
	QQPLOT;
	RUN;
/* Run ANOVA Model WITHOUT BLOCK EFFECT */
PROC ANOVA DATA = Bowlers;
	CLASS Bowler;
	MODEL Score = Bowler;
	MEANS Bowler / BON TUKEY LSD CLDIFF HOVTEST=LEVENE WELCH;
	TITLE 'Compare Score Across Bowlers ';
	RUN;

/* Non-parametric Test
Also gives results of Kruskal-Wallis Test
which tests equality of treatment means */
PROC NPAR1WAY WILCOXON DATA = Bowlers;
   CLASS Bowler;
   VAR Score;
   EXACT WILCOXON / MC;
RUN;

/* Run ANOVA Model WITHOUT BLOCK EFFECT */
PROC GLM DATA = Bowlers;
	CLASS Bowler;
	MODEL Score = Bowler;
	LSMEANS Bowler / PDIFF CL ADJUST=tukey;
	Output Out = result1 P= predict R = residual;
	RUN;

/* Normality Check for Residuals */
PROC UNIVARIATE DATA = result1 NORMAL PLOT;
	VAR residual;
	RUN;

/* PLOT Residual vs Predicted Value Variance Check
Helps to check for interaction effects*/
PROC SGPLOT DATA = result1;
SCATTER X = predict Y = residual;
REFLINE 0 / axis=Y;
	TITLE 'Residual vs Predicted Value Variance Check';
RUN;

/* Plot Residuals vs Predicted Value Variance Check
BY BLOCK */
PROC SGPLOT DATA = result1;
SCATTER X = predict Y = residual /
	markerattrs=(symbol=CircleFilled)
	datalabel = Bowler
	GROUP = Bowler;
REFLINE 0 / axis=Y;
RUN;
PROC MIXED DATA=Bowlers;
CLASS bowler;
MODEL score=;
RANDOM bowler;
RUN;
