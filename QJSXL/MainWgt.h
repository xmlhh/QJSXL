/************************************************************************
*   文件名称：MainWgt.h
*   编写人员：LHH
*   创建日期：2017/04/01
*   功能描述：主窗口: 极速迅雷的UI界面风格
*   备    注：
*   修改描述：
************************************************************************/

#ifndef MAINWGT_H
#define MAINWGT_H


#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QButtonGroup>

namespace Ui {
class MainWgt;
}

class MainWgt : public QWidget
{
    Q_OBJECT

public:
    explicit MainWgt(QWidget *parent = 0);
    ~MainWgt();

    /*@author by lhh
    * @brief 绘制事件
    * @param QPaintEvent
    * @return void
    */
    void paintEvent(QPaintEvent* e);

    /*@author by lhh
    * @brief 鼠标按下
    * @param QMouseEvent
    * @return void
    */
    void mousePressEvent(QMouseEvent*);

    /*@author by lhh
    * @brief 鼠标移动
    * @param QMouseEvent
    * @return void
    */
    void mouseMoveEvent(QMouseEvent*);

    /*@author by lhh
    * @brief 鼠标释放
    * @param QMouseEvent
    * @return void
    */
    void mouseReleaseEvent(QMouseEvent*);

public:
    /*@author by lhh
    * @brief 窗口初始化
    * @param 无
    * @return void
    */
    void WinInit();

    /*@author by lhh
    * @brief 信号与槽的连接
    * @param 无
    * @return void
    */
    void Connects();

private slots:
    /*@author by lhh
    * @brief 关闭窗口
    * @param 无
    * @return void
    */
    void OnCloseBtn();

    /*@author by lhh
    * @brief 最大化/还原
    * @param 无
    * @return void
    */
    void OnMaxBtn();

    /*@author by lhh
    * @brief 最小化
    * @param 无
    * @return void
    */
    void OnMinBtn();

    /*@author by lhh
    * @brief 配置
    * @param 无
    * @return void
    */
    void OnConfigBtn();

    /*@author by lhh
    * @brief 配置
    * @param 无
    * @return void
    */
    void OnStyleBtn();

    void OnGroupClickedBtn(QAbstractButton* cBtn);

private:
    Ui::MainWgt *ui;

    QPixmap borderPix;  // 阴影图片
    int x_local;		//鼠标x
    int y_local;		//鼠标y
    bool pressed_left;	//鼠标左键是否按下

    bool m_bFlag;       // 最大化/最小化标识


    QButtonGroup *m_pGroupBtn;
    bool m_bFlagBtn;
};

#endif // MAINWGT_H
