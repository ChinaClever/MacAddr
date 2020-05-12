/*
 * 配置文件公共基类
 *
 *  Created on: 2018年1月1日
 *      Author: Lzy
 */
#include "configbase.h"

ConfigBase::ConfigBase()
{
    item = new sConfigItem();
    item->serial = nullptr;
}

ConfigBase *ConfigBase::bulid()
{
    static ConfigBase* sington = nullptr;
    if(sington == nullptr)
        sington = new ConfigBase();
    return sington;
}


/**
 * @brief 获取串口名称
 * @return 串口名
 */
QString ConfigBase::getSerialName()
{
    QString prefix = getPrefix();
    QString str = QString("%1_COM").arg(prefix);
    return com_cfg_readStr(str, prefix);
}

/**
 * @brief 设置串口名
 * @param name
 */
void ConfigBase::setSerialName(const QString &name)
{
    QString prefix = getPrefix();
    QString str = QString("%1_COM").arg(prefix);
    com_cfg_write(str, name, prefix);
}
