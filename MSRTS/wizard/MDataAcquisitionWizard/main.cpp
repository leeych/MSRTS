
#include <QApplication>
#include "mdataacquitionwizard.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MDataAcquitionWizard *wizard = new MDataAcquitionWizard;
    wizard->exec();

    return app.exec();
}
