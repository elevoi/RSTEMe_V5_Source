#ifndef EMODULE_H
#define EMODULE_H

#include <device/edevice.h>


class EModule : public EDevice
{
public:
    explicit EModule(QObject *parent = nullptr);
    ~EModule();
    /* Exported types ------------------------------------------------------------*/


    /* Exported constants --------------------------------------------------------*/


    /* Exported macro ------------------------------------------------------------*/


    /* Exported properties -------------------------------------------------------*/

    /* Exported functions prototypes ---------------------------------------------*/

private:
    /* Private variables ---------------------------------------------------------*/

    /* Private functions prototypes -----------------------------------------------*/
};

#endif // EMODULE_H
