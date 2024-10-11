#include "Node.hpp"
#include <stdexcept>  // For exception handling

// Constructor Implementation
Node::Node(int nodeNumberInput, int problemDimensionInput, const std::vector<double>& materialPositionInput, const std::vector<int>& elementListInput)
        : problemDimension(problemDimensionInput),
          nodeNumber(nodeNumberInput),
          materialPosition(materialPositionInput),
          spatialPosition(materialPositionInput), // Initialize spatialPosition with the same values as materialPosition
          elementList(elementListInput),
          boundaryConditions(problemDimensionInput, 1.0),          // Initialize with ones
          boundaryConditionValues(problemDimensionInput, 0.0),     // Initialize with zeros
          degreesOfFreedom(problemDimensionInput, 0.0)             // Initialize with zeros
{
    // Validate the size of materialPosition
    if (static_cast<int>(materialPosition.size()) != problemDimension) {
        throw std::invalid_argument("Size of materialPosition does not match problemDimension.");
    }

    // Optionally, validate other inputs (e.g., elementList size)
    if (elementList.empty()) {
        throw std::invalid_argument("Element list (elementList) cannot be empty.");
    }

    // Initialize Gauss Point related vectors
    int gaussPointSize = 2 * problemDimension * problemDimension; // PD*PD + PD*PD = 2*PD*PD

    gaussPointBoundaryConditions = std::vector<double>(gaussPointSize, 1.0); // Initialize with ones
    gaussPointDegreesOfFreedom = std::vector<double>(gaussPointSize, 0.0);    // Initialize with zeros
    gaussPointValues = std::vector<double>(gaussPointSize, 0.0);              // Initialize with zeros
}

// Destructor Implementation
Node::~Node() {
    // No manual cleanup required for std::vector
    // Optional: Uncomment the following line for debugging purposes
    // std::cout << "Destructor called for Node Number: " << nodeNumber << std::endl;
}

// Getter Implementations
int Node::getProblemDimension() const {
    return problemDimension;
}

int Node::getNodeNumber() const {
    return nodeNumber;
}

const std::vector<double>& Node::getMaterialPosition() const {
    return materialPosition;
}

const std::vector<double>& Node::getSpatialPosition() const {
    return spatialPosition;
}

const std::vector<int>& Node::getElementList() const {
    return elementList;
}

const std::vector<double>& Node::getBoundaryConditions() const {
    return boundaryConditions;
}

const std::vector<double>& Node::getBoundaryConditionValues() const {
    return boundaryConditionValues;
}

const std::vector<double>& Node::getDegreesOfFreedom() const {
    return degreesOfFreedom;
}

const std::vector<double>& Node::getGaussPointBoundaryConditions() const {
    return gaussPointBoundaryConditions;
}

const std::vector<double>& Node::getGaussPointDegreesOfFreedom() const {
    return gaussPointDegreesOfFreedom;
}

const std::vector<double>& Node::getGaussPointValues() const {
    return gaussPointValues;
}

// Setter Implementations
void Node::setMaterialPosition(const std::vector<double>& newMaterialPosition) {
    if (static_cast<int>(newMaterialPosition.size()) != problemDimension) {
        throw std::invalid_argument("Size of newMaterialPosition does not match problemDimension.");
    }
    materialPosition = newMaterialPosition;
}

void Node::setSpatialPosition(const std::vector<double>& newSpatialPosition) {
    if (static_cast<int>(newSpatialPosition.size()) != problemDimension) {
        throw std::invalid_argument("Size of newSpatialPosition does not match problemDimension.");
    }
    spatialPosition = newSpatialPosition;
}

// (Optional) Implement other setters as needed
