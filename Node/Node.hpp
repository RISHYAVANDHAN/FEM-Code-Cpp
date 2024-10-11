#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
public:
    // Constructor
    Node(int nodeNumber, int problemDimension, const std::vector<double>& materialPosition, const std::vector<int>& elementList);

    // Destructor
    ~Node();

    // Getter methods
    int getProblemDimension() const;
    int getNodeNumber() const;
    const std::vector<double>& getMaterialPosition() const;
    const std::vector<double>& getSpatialPosition() const;
    const std::vector<int>& getElementList() const;
    const std::vector<double>& getBoundaryConditions() const;
    const std::vector<double>& getBoundaryConditionValues() const;
    const std::vector<double>& getDegreesOfFreedom() const;
    const std::vector<double>& getGaussPointBoundaryConditions() const;
    const std::vector<double>& getGaussPointDegreesOfFreedom() const;
    const std::vector<double>& getGaussPointValues() const;

    // Setter methods (if needed)
    void setMaterialPosition(const std::vector<double>& newMaterialPosition);
    void setSpatialPosition(const std::vector<double>& newSpatialPosition);
    // Add more setters as required

private:
    // Properties
    int problemDimension;                         // Problem Dimension
    int nodeNumber;                               // Node Number
    std::vector<double> materialPosition;         // Node position in material configuration
    std::vector<double> spatialPosition;          // Node position in spatial configuration
    std::vector<int> elementList;                 // Element list
    std::vector<double> boundaryConditions;        // Boundary conditions corresponding to node unknowns
    std::vector<double> boundaryConditionValues;   // Boundary condition values corresponding to node unknowns
    std::vector<double> degreesOfFreedom;          // Degrees of freedom corresponding to the unknowns
    std::vector<double> gaussPointBoundaryConditions; // Boundary conditions at Gauss Points
    std::vector<double> gaussPointDegreesOfFreedom;   // Degrees of freedom at Gauss Points
    std::vector<double> gaussPointValues;             // Gauss point values written from the Gauss points
};

#endif // NODE_H
