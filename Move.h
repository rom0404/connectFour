#ifndef MOVE_H
#define MOVE_H
class Move
{
private:

public:
	int row, column, id;
	Move(int rowinit, int columninit, int idinit) {
		row = rowinit;
		column = columninit;
		id = idinit;
	}
};
#endif // !MOVE_H



