// -- ���������   �������e��� (������������ ����������������)
int levenshtein(
	int lx,           // ����� ����� x 
	const char x[],   // ����� ������ lx
	int ly,           // ����� ����� y
	const char y[]    // ����� y
);
// -- ���������   �������e��� (��������)
int levenshtein_r(
	int lx,           // ����� ������ x 
	const char x[],   // ������ ������ lx
	int ly,           // ����� ������ y
	const char y[]    // ������ y
);

int lcs(
    int lenx,         // �����   ������������������  X   
    const char x[],   // ������������������ X
    int leny,         // �����   ������������������  Y
    const char y[]    // ������������������ Y
);
int lcsd(
    const char x[],  // ������������������ X
    const char y[],  // ������������������  Y
    char z[]         // ���������� ����� ��������������������� 
);