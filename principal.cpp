#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //crear el lienzo
    lienzo =QPixmap(500,500);
    //invocar al metodo dibujar
    this->dibujar();
    //mostrar el lienzo en el cuadro
    ui->cuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    //rellenar lienzo de color blanco
    lienzo.fill(Qt::white);

    //crear el pintor
    QPainter painter(&lienzo);

    int x = 50;
    int y = 50;
    int ancho=100;
    int alto_1 = ui->inNota1->value();
    int alto_2 =ui->inNota2->value();
    int alto_3=ui->inNota3->value();;

    //crear un pincel para el borde
    QPen pincel;
    pincel.setWidth(5);

    //crear un nuevo color (rgb de color) para el borde y rellono
    QColor colorBorde1(157,195,230);
    QColor colorRelleno1(231, 231,255);

    pincel.setColor(colorBorde1);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    ///pincel.setJoinStyle(Qt::MiterJoin);

    //establecer el pincel al pintor
   /// painter.setPen(pincel);

    //dibujar la primera barra
    painter.drawRect(x,y+(400-alto_1), ancho,alto_1);

    //crear un nuevo color (rgb de color) para el borde y rellono
    QColor colorBorde2(112,48,160);
    QColor colorRelleno2(250,210,245);


    //establecer el nuevo color al pincel
    pincel.setColor(colorBorde2);

    //volver a establecer el pincel al objeto paincer
    painter.setPen(pincel);

    //establecer el color de la brocha del objeto painter
    painter.setBrush(colorRelleno2);

    //dibujar la segunda barra
    painter.drawRect(x+150,y+(400-alto_2), ancho, alto_2);

    //creando los colores de la tercera bbarra
    QColor colorRelleno3(255,242,204);
    QColor colorBorder3(244, 177, 131);

    //establece nuevo color al pincel
    pincel.setColor(colorBorder3);

    //establecer el pincel y la brocha del painter
    painter.setPen(pincel);
    painter.setBrush(colorRelleno3);

    //dibuja la tercera barra
    painter.drawRect(x+300, y+(400-alto_3),ancho, alto_3);

    //muestra el lienzo en el "cuadro"
    ui->cuadro->setPixmap(lienzo);
}


void Principal::on_cmdGraficar_clicked()
{
    dibujar();
}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_actionGuardar_triggered()
{
    QString nombreAr= QFileDialog::getSaveFileName(
                this, "Guardar imagen", QString(), "Imagenes (*.png");
    if (!nombreAr.isEmpty()){
        if(lienzo.save(nombreAr))
            QMessageBox::information(this, "Guardar imagen", "Archivo guardado en: " + nombreAr);
        else
            QMessageBox::warning(this, "Guardar imagen", "No se pudo guardar el archivo");
    }
}

