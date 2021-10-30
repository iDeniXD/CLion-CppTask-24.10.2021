#include "Canvas.hpp"
#include "AllegroBase.hpp"


Canvas::Canvas()
{
}
Canvas::~Canvas()
{
    for(int i=0; i < figures_.GetSize(); i++) {
        delete figures_.Get(i);
    }
}
void Canvas::Draw()
{
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) ); // Clear creen
    for(int i = 0; i < figures_.GetSize(); i++) {
        figures_.Get(i)->Draw();
    }
}
void Canvas::NextFrame()
{
    for(int i = 0; i < figures_.GetSize(); i++) {
        figures_.Get(i)->Move();
    }
}
void Canvas::Add(Figure *f)
{
    figures_.Add(f);
}
void Canvas::Remove(int i)
{
    figures_.Remove(i);
}
