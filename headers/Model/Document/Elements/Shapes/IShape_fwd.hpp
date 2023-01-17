#ifndef COMMAND_DOCUMENT_ELEMENTS_ISHAPE_FWD_HPP
#define COMMAND_DOCUMENT_ELEMENTS_ISHAPE_FWD_HPP

class IShape;

using IShapeRawPtr = IShape *;

using IShapePtr = std::unique_ptr<IShape>;
using IShapePtrConst = std::unique_ptr<const IShape>;
using IShapeSharedPtr = std::shared_ptr<IShape>;
using IShapeSharedPtrConst = std::shared_ptr<const IShape>;

#endif
