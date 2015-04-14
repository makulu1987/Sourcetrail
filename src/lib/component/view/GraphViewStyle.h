#ifndef GRAPH_VIEW_STYLE_H
#define GRAPH_VIEW_STYLE_H

#include <map>
#include <memory>

#include "component/view/graphElements/GraphNode.h"
#include "component/view/GraphViewStyleImpl.h"
#include "data/graph/Node.h"

class GraphViewStyle
{
public:
	struct NodeMargins
	{
		NodeMargins();

		int left;
		int right;

		int top;
		int bottom;

		int spacingX;
		int spacingY;

		int minWidth;
		float charWidth;
	};

	struct NodeStyle
	{
		NodeStyle();

		std::string color;

		std::string shadowColor;
		int shadowBlurRadius;

		int cornerRadius;

		float borderWidth;
		std::string borderColor;
		bool borderDashed;

		std::string fontName;
		size_t fontSize;
		bool fontBold;

		Vec2i textOffset;

		bool undefinedPattern;
	};

	struct EdgeStyle
	{
		EdgeStyle();

		std::string color;

		float width;
		int zValue;

		bool isStraight;

		int arrowLength;
		int arrowWidth;
		bool arrowClosed;

		int cornerRadius;
		int verticalOffset;

		Vec2i originOffset;
		Vec2i targetOffset;
	};

	static std::shared_ptr<GraphViewStyleImpl> getImpl();
	static void setImpl(std::shared_ptr<GraphViewStyleImpl> impl);

	static float getCharWidthForNodeType(Node::NodeType type);

	static size_t getFontSizeForNodeType(Node::NodeType type);
	static size_t getFontSizeOfAccessNode();
	static size_t getFontSizeOfNumber();

	static std::string getFontNameForNodeType(Node::NodeType type);
	static std::string getFontNameOfAccessNode();
	static std::string getFontNameOfNumber();

	static NodeMargins getMarginsForNodeType(Node::NodeType type, bool hasChildren);
	static NodeMargins getMarginsOfAccessNode(bool expanded, size_t subNodeCount, size_t invisibleSubNodeCount);

	static NodeStyle getStyleForNodeType(Node::NodeType type, bool isActive, bool isFocused, bool hasChildren);
	static NodeStyle getStyleOfAccessNode();

	static EdgeStyle getStyleForEdgeType(Edge::EdgeType type, bool isActive, bool isFocused);

private:
	static std::map<Node::NodeType, float> s_charWidths;
	static std::shared_ptr<GraphViewStyleImpl> s_impl;
};

#endif // GRAPH_VIEW_STYLE_H