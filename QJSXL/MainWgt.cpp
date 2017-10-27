#include "MainWgt.h"
#include "ui_MainWgt.h"

#define WIN_WIDTH 1000
#define WIN_HIEGHT 660

//const int BORDER = 20;
const int BORDER = 0;

MainWgt::MainWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWgt)
  , x_local(0)
  , y_local(0)
  , pressed_left(false)
  , m_bFlag(true)
  , m_bFlagBtn(true)
{

    WinInit();

}

MainWgt::~MainWgt()
{
    delete ui;
}


/*@author by lhh
* @brief 鼠标按下
* @param QMouseEvent
* @return void
*/
void MainWgt::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        x_local = e->x();
        y_local = e->y();
        pressed_left = true;
    }
}

/*@author by lhh
* @brief 鼠标移动
* @param QMouseEvent
* @return void
*/
void MainWgt::mouseMoveEvent(QMouseEvent* e)
{
    int x_mouse = e->globalX();
    int y_mouse = e->globalY();

    if(pressed_left)
    {
        move(x_mouse-x_local, y_mouse-y_local);
    }
}

/*@author by lhh
* @brief 鼠标释放
* @param QMouseEvent
* @return void
*/
void MainWgt::mouseReleaseEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        pressed_left = false;
    }
}

/*@author by lhh
* @brief 绘制事件
* @param QPaintEvent
* @return void
*/
void MainWgt::paintEvent(QPaintEvent* /*e*/)
{
    QPainter painter(this);

#if 0
    /* 阴影绘制，四个边框，宽度BORDER */
    painter.drawPixmap(QPoint(0, 0), borderPix, QRect(0, 0, BORDER, BORDER));


    painter.drawPixmap(QPoint(0, height() - BORDER)
                        , borderPix
                        , QRect(0, borderPix.height() - BORDER, BORDER, BORDER));

    painter.drawPixmap(QPoint(width() - BORDER, 0)
                        , borderPix
                        , QRect(borderPix.width() - BORDER, 0, BORDER, BORDER));

    painter.drawPixmap(QPoint(width() - BORDER, height() - BORDER)
                        , borderPix
                        , QRect(borderPix.width() - BORDER, borderPix.height() - BORDER, BORDER, BORDER));

    painter.drawPixmap(QRect(0, BORDER, BORDER, height() - BORDER * 2)
                        , borderPix
                        , QRect(0, BORDER, BORDER, borderPix.height() - BORDER * 2));

    painter.drawPixmap(QRect(width() - BORDER, BORDER, BORDER, height() - BORDER * 2)
                        , borderPix
                        , QRect(borderPix.width() - BORDER, BORDER, BORDER, borderPix.height() - BORDER * 2));

    painter.drawPixmap(QRect(BORDER, 0, width() - BORDER * 2, BORDER)
                        , borderPix
                        , QRect(BORDER, 0,borderPix.width() - BORDER * 2, BORDER));

    painter.drawPixmap(QRect(BORDER, height() - BORDER, width() - BORDER * 2, BORDER)
                        , borderPix
                        , QRect(BORDER, borderPix.height() - BORDER, borderPix.width() - BORDER * 2, BORDER));


    /* 背景 */
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(QRect(BORDER, BORDER, width() - BORDER * 2, height() - BORDER * 2)
                    , QBrush(QColor(55, 64, 72, 250)));

#endif

}


/*@author by lhh
* @brief 窗口初始化
* @param 无
* @return void
*/
void MainWgt::WinInit()
{
    ui->setupUi(this);
    //ui->setupUi(m_pCenterWidget);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setWindowOpacity(0.95);

    resize(WIN_WIDTH, WIN_HIEGHT);

    //setShowMinBtn(true);
    //setMaxable(true);
    //setResizable(true);

    //borderPix = QPixmap(":/Data/Image/borderBack.png");
    //borderPix = QPixmap(":/Data/Image/qjsxl.png");

    Connects();

    // 按钮组
    m_pGroupBtn = new QButtonGroup;
    m_pGroupBtn->addButton(ui->m_pCloudDiskBtn, 1);
    m_pGroupBtn->addButton(ui->m_pUpingBtn, 2);
    m_pGroupBtn->addButton(ui->m_pDownloadingBtn, 3);
    m_pGroupBtn->addButton(ui->m_pUpSuccessBtn, 4);
    m_pGroupBtn->addButton(ui->m_pDownSuccessBtn, 5);
}

/*@author by lhh
* @brief 信号与槽的连接
* @param 无
* @return void
*/
void MainWgt::Connects()
{

    connect(ui->m_pCloseBtn, SIGNAL(clicked()), this, SLOT(OnCloseBtn()));
    connect(ui->m_pMaxBtn, SIGNAL(clicked()), this, SLOT(OnMaxBtn()));
    connect(ui->m_pMinBtn, SIGNAL(clicked()), this, SLOT(OnMinBtn()));
    connect(ui->m_pConfigBtn, SIGNAL(clicked()), this, SLOT(OnConfigBtn()));
    connect(ui->m_pStyleBtn, SIGNAL(clicked()), this, SLOT(OnStyleBtn()));
    connect(m_pGroupBtn, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(OnGroupClickedBtn(QAbstractButton*)));

}


/*@author by lhh
* @brief 关闭窗口
* @param 无
* @return void
*/
void MainWgt::OnCloseBtn()
{
    close();
}

/*@author by lhh
* @brief 最大化/还原
* @param 无
* @return void
*/
void MainWgt::OnMaxBtn()
{
    if(m_bFlag)
    {
        showMaximized();
    }
    else
    {
        showNormal();
    }

    m_bFlag = !m_bFlag;
}

/*@author by lhh
* @brief 最小化
* @param 无
* @return void
*/
void MainWgt::OnMinBtn()
{
    showMinimized();
}

/*@author by lhh
* @brief 配置
* @param 无
* @return void
*/
void MainWgt::OnConfigBtn()
{

}

/*@author by lhh
* @brief 配置
* @param 无
* @return void
*/
void MainWgt::OnStyleBtn()
{

}


/*@author by lhh
* @brief 按钮组的槽，组内按钮互斥
* @param 当前点击的按钮
* @return void
*/
void MainWgt::OnGroupClickedBtn(QAbstractButton* cBtn)
{
    if  (m_bFlagBtn)
    {
        cBtn->setChecked(m_bFlagBtn);
    }
}
