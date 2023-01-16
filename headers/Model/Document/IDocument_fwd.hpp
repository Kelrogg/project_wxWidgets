#ifndef COMMAND_DOCUMENT_IDOCUMENT_FWD_HPP
#define COMMAND_DOCUMENT_IDOCUMENT_FWD_HPP

class IDocument;

using IDocumentRawPtr = IDocument*;

using IDocumentPtr = std::unique_ptr<IDocument>;
using IDocumentSharedPtr = std::shared_ptr<IDocument>;
using IDocumentWeakPtr = std::weak_ptr<IDocument>;

#endif
