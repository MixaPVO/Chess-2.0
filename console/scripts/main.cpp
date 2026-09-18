//DON'T EDIT
#include <io.h>
#include <fcntl.h>

#include "GameManagement.h"

int main()
{
	 _setmode(_fileno(stdout), _O_U16TEXT);

    GameManagement gameManagement;
    gameManagement.Update();
    return 0;
}