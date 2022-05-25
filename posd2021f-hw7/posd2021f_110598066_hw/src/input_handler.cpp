#include "input_handler.h"

void InputHandler::handle()
{

    int _inputShapeInt;

    while (std::cin >> _inputShapeInt)
    {
        switch (_inputShapeInt)
        {
        case 1:
            addCircle();
            break;
        case 2:
            addRectangle();
            break;
        case 3:
            addTriangle();
            break;
        case 4:
            addCompound();
            break;
        case 5:
            save();
            break;
        case 6:
            isContinued = false;
            break;

        default:
            break;
        }
        if (!isContinued)
        {
            delete result;
            delete builder;
            break;
        }
    }
}

void InputHandler::printEditorInstructions() {}

void InputHandler::handleEditorInstructions(int instruction) {}

void InputHandler::save()
{
    std::ofstream newFile;
    std::string filename;
    std::cout << "Please enter the file name to save the shape:" << std::endl;
    std::cin >> filename;
    filename += ".txt";

    // Write to the file
    std::cout << filename << std::endl;
    newFile.open("test/data/" + filename);
    result = builder->getShape();

    ShapeInfoVisitor visitor;
    result->accept(&visitor);
    std::string resultText = visitor.getResult();
    newFile << resultText;
    newFile.close();
}

void InputHandler::addCircle()
{
    float radius = 0;
    std::cout << "Radius of circle:";
    std::cin >> radius;
    std::cout << "circle added." << std::endl;
    builder->buildCircle(radius);
}

void InputHandler::addRectangle()
{
    float width = 0;
    float height = 0;
    std::cout << "Width of rectangle:";
    std::cin >> width;
    std::cout << "Height of rectangle:";
    std::cin >> height;
    std::cout << "rectangle added." << std::endl;
    builder->buildRectangle(width, height);
}

void InputHandler::addTriangle()
{
    float X1 = 0;
    float Y1 = 0;
    float X2 = 0;
    float Y2 = 0;
    std::cout << "X1 of triangle:";
    std::cin >> X1;
    std::cout << "Y1 of triangle:";
    std::cin >> Y1;
    std::cout << "X2 of triangle:";
    std::cin >> X2;
    std::cout << "Y2 of triangle:";
    std::cin >> Y2;
    std::cout << "triangle added." << std::endl;
    builder->buildTriangle(X1, Y1, X2, Y2);
}

void InputHandler::printCompoundInstructions() {}

void InputHandler::handleCompoundInstructions(int instruction) {}

void InputHandler::addCompound()
{
    std::cout << "Shape:";
    int compoundShapeInt;
    bool isCompoundShapeComplete = false;
    builder->buildCompoundBegin();
    while (std::cin >> compoundShapeInt)
    {
        switch (compoundShapeInt)
        {
        case 1:
            addCircle();
            break;
        case 2:
            addRectangle();
            break;
        case 3:
            addTriangle();
            break;
        case 4:
            addCompound();
            break;
        case 5:
            std::cout << "Compound added.";
            builder->buildCompoundEnd();
            isCompoundShapeComplete = true;
            break;
        case 6:
            isContinued = false;
            break;

        default:
            break;
        }
        if (isCompoundShapeComplete)
        {
            break;
        }
    }
}